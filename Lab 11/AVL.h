bool bst_search(struct node * root, int key);
struct node * insert_node(struct node ** root, int data);
bool delete_node(struct node * root, int data);

bool save_pre_order(struct node * root, FILE * fptr);
bool save_in_order(struct node * root, FILE * fptr);
bool save_post_order(struct node * root, FILE * fptr);
void load_tree(struct node * root, FILE * fptr);

int find_smallest_node(struct node * root);

void print_pre_order(struct node * root);
void print_post_order(struct node * root);
void print_in_order(struct node * root);


struct node * insert(struct node *T,int x);
int BF(struct node *T);
struct node * RL(struct node *T);
struct node * LR(struct node *T);
struct node * LL(struct node *T);
struct node * RR(struct node *T);
struct node * rotateleft(struct node *x);
struct node * rotateright(struct node *x);
int height(struct node *T);
