#include <stdio.h>
#include "expenses.h"

int main(void) {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    float limit = 0.0f;

    printf("------ SMART DAILY EXPENSE TRACKER ------\n");
    inputExpenses(expenses, &count, &limit);

    float total = calculateTotal(expenses, count);
    printReport(expenses, count, total, limit);

    return 0;
}
