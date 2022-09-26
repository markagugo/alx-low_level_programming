#include "hash_tables.h"

/**
 * str_copy1 - Creates a copy of a given string.
 * @s: The string to copy.
 *
 * Return: A pointer to the created string, otherwise NULL.
 */
char *str_copy1(const char *s)
{
	int i, len;
	char *s_c = NULL;

	if (s != NULL)
	{
		len = strlen(s);
		s_c = malloc(sizeof(char) * (len + 1));
		if (s_c != NULL)
		{
			for (i = 0; i < len; i++)
				s_c[i] = s[i];
			s_c[i] = '\0';
		}
	}
	return (s_c);
}

/**
 * shash_table_create - Creates a new sorted hash table.
 * @size: The maximum number of top-level items in the hash table.
 *
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *tbl = NULL;
	unsigned long int i;

	tbl = malloc(sizeof(shash_table_t));
	if (tbl != NULL)
	{
		tbl->array = malloc(sizeof(shash_node_t *) * size);
		if (tbl->array != NULL)
		{
			for (i = 0; i < size; i++)
				tbl->array[i] = NULL;
		}
		tbl->size = size;
		tbl->shead = NULL;
		tbl->stail = NULL;
	}
	return (tbl);
}

/**
 * insert_shash_node - Inserts a hash node into a \
 * hash table's sorted list.
 * @ht: The hash table.
 * @hn: The hash node to be inserted.
 */
void insert_shash_node(shash_table_t *ht, shash_node_t *hn)
{
	shash_node_t *next = NULL, *prev = NULL;

	if ((ht != NULL) && (hn != NULL))
	{
		next = ht->shead;
		while (next != NULL)
		{
			if (strcmp(next->key, hn->key) < 0)
				prev = next, next = next->snext;
			else
				break;
		}
		if (next != NULL)
			next->sprev = hn;
		if (prev != NULL)
		{
			prev->snext = hn;
			hn->sprev = prev;
			hn->snext = next;
			if (next == NULL)
				ht->stail = hn;
		}
		else
		{
			hn->sprev = NULL;
			hn->snext = next;
			ht->shead = hn;
			if (ht->stail == NULL)
				ht->stail = hn;
		}
	}
}

/**
 * shash_table_set - Adds an element to a given sorted hash table.
 * @ht: The sorted hash table that will contain the element.
 * @key: The key of the element to add.
 * @value: The value of the element to add.
 *
 * Return: 1 if the addition was successful, otherwise 0.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long idx;
	shash_node_t *tmp = NULL, *new_node = NULL;

	if ((ht != NULL) && (ht->array != NULL)
		&& (key != NULL) && (strlen(key) > 0))
	{
		idx = key_index((unsigned char *)key, ht->size);
		tmp = ht->array[idx];
		while (tmp != NULL)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				free(tmp->value);
				tmp->value = str_copy1(value);
				return (1);
			}
			tmp = tmp->next;
		}
		tmp = ht->array[idx];
		new_node = malloc(sizeof(shash_node_t));
		if (new_node != NULL)
		{
			new_node->key = str_copy1(key);
			new_node->value = str_copy1(value);
			new_node->next = tmp;
			ht->array[idx] = new_node;
			/* apply the sorting */
			insert_shash_node(ht, new_node);
			return (1);
		}
	}
	return (0);
}

/**
 * shash_table_get - Retrieves the value of an element with a given \
 * key in a sorted hash table.
 * @ht: The sorted hash table to search.
 * @key: The element's key.
 *
 * Return: The value of the element associated with the given \
 * key, otherwise NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long idx;
	shash_node_t *node = NULL;

	if ((ht != NULL) && (ht->array != NULL)
		&& (key != NULL) && (strlen(key) > 0))
	{
		idx = key_index((unsigned char *)key, ht->size);
		node = ht->array[idx];
		while (node != NULL)
		{
			if (strcmp(node->key, key) == 0)
				return (node->value);
			node = node->next;
		}
	}
	return (NULL);
}

/**
 * shash_table_print - Prints the elements of a sorted hash table.
 * @ht: A pointer to the hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	char first = TRUE;

	if ((ht != NULL) && (ht->array != NULL))
	{
		printf("{");
		fflush(stdout);
		node = ht->shead;
		while (node != NULL)
		{
			printf("%s'%s': '%s'", first ? "" : ", ", node->key, node->value);
			fflush(stdout);
			first = FALSE;
			node = node->snext;
		}
		printf("}\n");
		fflush(stdout);
	}
}

/**
 * shash_table_print_rev - Prints the elements of a sorted \
 * hash table in reverse.
 * @ht: A pointer to the hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	char first = TRUE;

	if ((ht != NULL) && (ht->array != NULL))
	{
		printf("{");
		fflush(stdout);
		node = ht->stail;
		while (node != NULL)
		{
			printf("%s'%s': '%s'", first ? "" : ", ", node->key, node->value);
			fflush(stdout);
			first = FALSE;
			node = node->sprev;
		}
		printf("}\n");
		fflush(stdout);
	}
}

/**
 * shash_table_delete - Deletes a sorted hash table and its elements.
 * @ht: A pointer to the hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node = NULL, *tmp = NULL;
	unsigned long i;

	if ((ht != NULL) && (ht->array != NULL))
	{
		for (i = 0; i < ht->size; i++)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				tmp = node->next;
				if (node->key != NULL)
					free(node->key);
				if (node->value != NULL)
					free(node->value);
				free(node);
				node = tmp;
			}
		}
		if (ht->array != NULL)
			free(ht->array);
		free(ht);
		ht = NULL;
	}
}