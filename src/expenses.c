#include <stdio.h>
#include <string.h>
#include "expenses.h"

/* Read input from stdin in this order:
   first line: n (number of expenses)
   second line: limit (float)
   followed by n lines: <category> <amount>
*/
void inputExpenses(Expense expenses[], int *count, float *limit) {
    int i;
    if (scanf("%d", count) != 1) {
        *count = 0;
        *limit = 0;
        return;
    }
    if (scanf("%f", limit) != 1) {
        *limit = 0;
    }
    for (i = 0; i < *count && i < MAX_EXPENSES; ++i) {
        scanf("%19s %f", expenses[i].category, &expenses[i].amount);
    }
}

float calculateTotal(const Expense expenses[], int count) {
    float total = 0.0f;
    for (int i = 0; i < count; ++i) total += expenses[i].amount;
    return total;
}

void printReport(const Expense expenses[], int count, float total, float limit) {
    printf("----------- DAILY REPORT -----------\n");
    printf("Category\tAmount (₹)\n");
    for (int i = 0; i < count; ++i) {
        printf("%-12s\t%.2f\n", expenses[i].category, expenses[i].amount);
    }
    printf("------------------------------------\n");
    printf("Total Spending: ₹%.2f\n", total);
    printf("Budget Limit:   ₹%.2f\n", limit);
    if (total > limit)
        printf("WARNING: You exceeded your limit by ₹%.2f!\n", total - limit);
    else
        printf("Good: You are under budget by ₹%.2f!\n", limit - total);
    printf("------------------------------------\n");
}
