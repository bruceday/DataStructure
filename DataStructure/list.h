typedef struct node node_t;

struct node
{
	int value;
	struct node *next;
};

node_t* create_node(int value);

void insert_sort(node_t *head);

void reverse(node_t *head);

void insert_node_h(node_t *head, node_t *node);

void insert_node_t(node_t *head, node_t *node);

void print_list(node_t *head);

void delete_list(node_t *head);

void test_list();

