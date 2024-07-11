// // BFS algorithm in C

// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 40

// struct queue {
//   int items[SIZE];
//   int front;
//   int rear;
// };

// struct queue* createQueue();
// void enqueue(struct queue* q, int);
// int dequeue(struct queue* q);
// void display(struct queue* q);
// int isEmpty(struct queue* q);
// void printQueue(struct queue* q);

// struct node {
//   int vertex;
//   struct node* next;
// };

// struct node* createNode(int);

// struct Graph {
//   int numVertices;
//   struct node** adjLists;
//   int* visited;
// };

// // BFS algorithm
// void bfs(struct Graph* graph, int startVertex) {
//   struct queue* q = createQueue();

//   graph->visited[startVertex] = 1;
//   enqueue(q, startVertex);

//   while (!isEmpty(q)) {
//     printQueue(q);
//     int currentVertex = dequeue(q);
//     printf("Visited %d\n", currentVertex);

//     struct node* temp = graph->adjLists[currentVertex];

//     while (temp) {
//       int adjVertex = temp->vertex;

//       if (graph->visited[adjVertex] == 0) {
//         graph->visited[adjVertex] = 1;
//         enqueue(q, adjVertex);
//       }
//       temp = temp->next;
//     }
//   }
// }

// // Creating a node
// struct node* createNode(int v) {
//   struct node* newNode = malloc(sizeof(struct node));
//   newNode->vertex = v;
//   newNode->next = NULL;
//   return newNode;
// }

// // Creating a graph
// struct Graph* createGraph(int vertices) {
//   struct Graph* graph = malloc(sizeof(struct Graph));
//   graph->numVertices = vertices;

//   graph->adjLists = malloc(vertices * sizeof(struct node*));
//   graph->visited = malloc(vertices * sizeof(int));

//   int i;
//   for (i = 0; i < vertices; i++) {
//     graph->adjLists[i] = NULL;
//     graph->visited[i] = 0;
//   }

//   return graph;
// }

// // Add edge
// void addEdge(struct Graph* graph, int src, int dest) {
//   // Add edge from src to dest
//   struct node* newNode = createNode(dest);
//   newNode->next = graph->adjLists[src];
//   graph->adjLists[src] = newNode;

//   // Add edge from dest to src
//   newNode = createNode(src);
//   newNode->next = graph->adjLists[dest];
//   graph->adjLists[dest] = newNode;
// }

// // Create a queue
// struct queue* createQueue() {
//   struct queue* q = malloc(sizeof(struct queue));
//   q->front = -1;
//   q->rear = -1;
//   return q;
// }

// // Check if the queue is empty
// int isEmpty(struct queue* q) {
//   if (q->rear == -1)
//     return 1;
//   else
//     return 0;
// }

// // Adding elements into queue
// void enqueue(struct queue* q, int value) {
//   if (q->rear == SIZE - 1)
//     printf("\nQueue is Full!!");
//   else {
//     if (q->front == -1)
//       q->front = 0;
//     q->rear++;
//     q->items[q->rear] = value;
//   }
// }

// // Removing elements from queue
// int dequeue(struct queue* q) {
//   int item;
//   if (isEmpty(q)) {
//     printf("Queue is empty");
//     item = -1;
//   } else {
//     item = q->items[q->front];
//     q->front++;
//     if (q->front > q->rear) {
//       printf("Resetting queue ");
//       q->front = q->rear = -1;
//     }
//   }
//   return item;
// }

// // Print the queue
// void printQueue(struct queue* q) {
//   int i = q->front;

//   if (isEmpty(q)) {
//     printf("Queue is empty");
//   } else {
//     printf("\nQueue contains \n");
//     for (i = q->front; i < q->rear + 1; i++) {
//       printf("%d ", q->items[i]);
//     }
//   }
// }

// int main() {
//   struct Graph* graph = createGraph(6);
//   addEdge(graph, 0, 1);
//   addEdge(graph, 0, 2);
//   addEdge(graph, 1, 2);
//   addEdge(graph, 1, 4);
//   addEdge(graph, 1, 3);
//   addEdge(graph, 2, 4);
//   addEdge(graph, 3, 4);

//   bfs(graph, 0);

//   return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 5
#define MAX_STRING_LENGTH 20

typedef struct {
    char Wawancara[MAX_STRING_LENGTH];
    char TesBakat[MAX_STRING_LENGTH];
    char Pengalaman[MAX_STRING_LENGTH];
    char Pendidikan[MAX_STRING_LENGTH];
    char Hasil[MAX_STRING_LENGTH];
} DataPoint;

typedef struct Node {
    char attribute[MAX_STRING_LENGTH];
    struct Node* branches[MAX_ROWS];
    int num_branches;
    char branch_values[MAX_ROWS][MAX_STRING_LENGTH];
    char result[MAX_STRING_LENGTH];
} Node;

double calculate_entropy(int class_count[], int total_instances) {
    double entropy = 0.0;
    for (int i = 0; i < 2; ++i) {
        if (class_count[i] > 0) {
            double probability = (double)class_count[i] / total_instances;
            entropy -= probability * log2(probability);
        }
    }
    return entropy;
}

int find_best_attribute(DataPoint dataset[], int rows) {
    int class_count[2] = {0};
    for (int i = 0; i < rows; ++i) {
        class_count[dataset[i].Hasil[0] - 'y']++;
    }

    double total_entropy = calculate_entropy(class_count, rows);
    double max_information_gain = 0.0;
    int best_attribute = -1;

    for (int i = 0; i < MAX_COLS - 1; ++i) {
        int value_count = 0;
        char values[MAX_ROWS][MAX_STRING_LENGTH];

        for (int j = 0; j < rows; ++j) {
            int exists = 0;
            for (int k = 0; k < value_count; ++k) {
                if (strcmp(values[k], dataset[j].Wawancara) == 0) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                strcpy(values[value_count], dataset[j].Wawancara);
                value_count++;
            }
        }

        double weighted_entropy = 0.0;
        for (int j = 0; j < value_count; ++j) {
            int count[2] = {0};
            for (int k = 0; k < rows; ++k) {
                if (strcmp(values[j], dataset[k].Wawancara) == 0) {
                    count[dataset[k].Hasil[0] - 'y']++;
                }
            }
            double probability = (double)count[j] / rows;
            weighted_entropy += probability * calculate_entropy(count, rows);
        }

        double information_gain = total_entropy - weighted_entropy;

        if (information_gain > max_information_gain) {
            max_information_gain = information_gain;
            best_attribute = i;
        }
    }
    return best_attribute;
}

Node* create_leaf_node(DataPoint dataset[], int rows) {
    int class_count[2] = {0};
    for (int i = 0; i < rows; ++i) {
        class_count[dataset[i].Hasil[0] - 'y']++;
    }

    Node* leaf = (Node*)malloc(sizeof(Node));
    strcpy(leaf->result, class_count[0] > class_count[1] ? "ya" : "tidak");
    leaf->num_branches = 0;
    return leaf;
}

Node* ID3(DataPoint dataset[], int rows) {
    int best_attribute = find_best_attribute(dataset, rows);

    if (best_attribute == -1) {
        return create_leaf_node(dataset, rows);
    }

    int value_count = 0;
    char values[MAX_ROWS][MAX_STRING_LENGTH];

    for (int j = 0; j < rows; ++j) {
        int exists = 0;
        for (int k = 0; k < value_count; ++k) {
            if (strcmp(values[k], dataset[j].Wawancara) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            strcpy(values[value_count], dataset[j].Wawancara);
            value_count++;
        }
    }

    Node* root = (Node*)malloc(sizeof(Node));
    strcpy(root->attribute, dataset[0].Wawancara);
    root->num_branches = value_count;

    for (int i = 0; i < value_count; ++i) {
        DataPoint* subset = (DataPoint*)malloc(rows * sizeof(DataPoint));
        int subset_rows = 0;

        for (int j = 0; j < rows; ++j) {
            if (strcmp(dataset[j].Wawancara, values[i]) == 0) {
                subset[subset_rows] = dataset[j];
                subset_rows++;
            }
        }

        root->branches[i] = ID3(subset, subset_rows);
        strcpy(root->branch_values[i], values[i]);
    }
    return root;
}

void print_tree(Node* root, int level) {
    for (int i = 0; i < level; ++i) {
        printf("\t");
    }
    printf("Attribute: %s\n", root->attribute);

    for (int i = 0; i < root->num_branches; ++i) {
        for (int j = 0; j < level; ++j) {
            printf("\t");
        }
        printf("Value: %s -> ", root->branch_values[i]);

        if (root->branches[i]->num_branches == 0) {
            printf("Result: %s\n", root->branches[i]->result);
        } else {
            printf("\n");
            print_tree(root->branches[i], level + 1);
        }
    }
}

int main() {
    DataPoint dataset[MAX_ROWS] = {
        {"Baik", "baik", "kurang", "d3", "ya"},
        {"Cukup", "kurang", "kurang", "s1", "tidak"},
        {"Baik", "cukup", "baik", "d3", "ya"},
        {"Baik", "baik", "baik", "s1", "ya"},
        {"Cukup", "cukup", "kurang", "d3", "tidak"},
        {"Kurang", "cukup", "kurang", "d3", "tidak"},
        {"Kurang", "cukup", "kurang", "s1", "tidak"},
        {"Baik", "baik", "baik", "d3", "ya"},
        {"Cukup", "baik", "kurang", "d3", "ya"},
        {"Cukup", "cukup", "kurang", "s1", "ya"}
    };

    Node* decision_tree = ID3(dataset, MAX_ROWS);

    printf("Decision Tree:\n");
    print_tree(decision_tree, 0);

    return 0;
}
