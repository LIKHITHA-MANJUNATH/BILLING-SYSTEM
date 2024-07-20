#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent an item
struct Item {
 char name[50];
 float price;
 int quantity;
 struct Item *next;
};
// Function to add an item to the linked list
struct Item *addItem(struct Item *head) {
 struct Item *newItem = (struct Item *)malloc(sizeof(struct Item));
 if (newItem == NULL) {
 printf("Memory allocation failed.\n");
 exit(EXIT_FAILURE);
 }
 printf("Enter item name: ");
 scanf("%s", newItem->name);
 printf("Enter item price: ");
 scanf("%f", &newItem->price);
 printf("Enter item quantity: ");
 scanf("%d", &newItem->quantity);
 newItem->next = NULL;
 if (head == NULL) {
 return newItem;
 } else {
 struct Item *current = head;
 while (current->next != NULL) {
 current = current->next;
 }
 current->next = newItem;
 return head;
 }
}
// Function to calculate the total bill amount using linked list
float calculateTotal(struct Item *head) {
 float total = 0.0,total1=0.0;
 struct Item *current = head;
 while (current != NULL) {
 total += current->price * current->quantity;
 total1=total*0.95;
 current = current->next;
 }
 printf("total amount after discount:%.2f\n",total1);
 return total;
}
// Function to generate a receipt using linked list
void generateReceipt(struct Item *head) {
 printf("\nReceipt:\n");
 printf("----------------------------\n");
 printf("Item\t\tPrice\t\tQuantity\t\ttotal discount 5%\n");
 printf("----------------------------\n");
 struct Item *current = head;
 while (current != NULL) {
 printf("%s\t\t%.2f\t\t%d\n", current->name, current->price, current->quantity);
 current = current->next;
 }
 printf("----------------------------\n");
 printf("Total Amount: %.2f\n", calculateTotal(head));
}
// Function to free the memory allocated for the linked list
void freeList(struct Item *head) {
 struct Item *current = head;
 while (current != NULL) {
 struct Item *temp = current;
 current = current->next;
 free(temp);
 }
}
struct Item *deleteItem(struct Item *head, char itemName[]) {
 struct Item *current = head;
 struct Item *prev = NULL;
 // Traverse the list to find the item to delete
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 // Found the item to delete
 if (prev == NULL) {
 // If it's the first item, update the head
 head = current->next;
 } else {
 // If it's not the first item, update the previous node's next pointer
 prev->next = current->next;
 }
 // Free the memory for the deleted item
 free(current);
 printf("Item '%s' deleted successfully.\n", itemName);
 return head; // Return the updated head
 }
 prev = current;
 current = current->next;
 }
 // If the item was not found
 printf("Item '%s' not found in the list.\n", itemName);
 return head; // Return the original head
}
int main() {
 struct Item *head = NULL; // Head of the linked list
 int numItems;
 printf("Enter the number of items: ");
 scanf("%d", &numItems);
 // Adding items to the linked list
 for (int i = 0; i < numItems; i++) {
 head = addItem(head);
 }
 // Generating and printing the receipt
 generateReceipt(head);
 // Deleting an item
char itemToDelete[50];
 printf("\nEnter the name of the item to delete: ");
 scanf("%s", itemToDelete);
 head = deleteItem(head, itemToDelete);
 // Generating and printing the updated receipt
 generateReceipt(head);
 // Freeing the memory allocated for the linked list
 freeList(head);
 return 0;
}
