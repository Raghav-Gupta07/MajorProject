
#ifndef EXPENSES_H
#define EXPENSES_H

#define MAX_EXPENSES 50
#define CATEGORY_LEN 20

typedef struct {
    char category[CATEGORY_LEN];
    float amount;
} Expense;

void inputExpenses(Expense expenses[], int *count, float *limit);

float calculateTotal(const Expense expenses[], int count);

void printReport(const Expense expenses[], int count, float total, float limit);

int saveExpenses(const char *filename, const Expense expenses[], int count, float limit);
int loadExpenses(const char *filename, Expense expenses[], int *count, float *limit);

#endif
