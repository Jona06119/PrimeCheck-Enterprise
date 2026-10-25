#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define APP_NAME "PrimeCheck Enterprise"
#define APP_VERSION "1.0.0"
#define MAX_INPUT 128

typedef enum {
    STATUS_OK = 0,
    STATUS_INVALID_INPUT,
    STATUS_OUT_OF_RANGE
} Status;

static Status read_integer(const char *prompt, int64_t *value)
{
    char buffer[MAX_INPUT];
    char *end;
    int64_t parsed;

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return STATUS_INVALID_INPUT;
    }

    if (strchr(buffer, '\n') == NULL && !feof(stdin)) {
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        return STATUS_INVALID_INPUT;
    }

    errno = 0;
    end = NULL;

    parsed = strtoimax(buffer, &end, 10);

    if (buffer == end || errno == ERANGE) {
        return STATUS_INVALID_INPUT;
    }

    while (isspace((unsigned char)*end)) {
        end++;
    }

    if (*end != '\0') {
        return STATUS_INVALID_INPUT;
    }

    *value = parsed;

    return STATUS_OK;
}

static bool is_prime(uint64_t number)
{
    uint64_t divisor;

    if (number < 2) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (divisor = 3;
         divisor <= number / divisor;
         divisor += 2) {

        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}

static void analyze_number(void)
{
    int64_t number;
    Status status;

    status = read_integer(
        "Enter an integer: ",
        &number
    );

    if (status != STATUS_OK) {
        printf("\n[ERROR] Invalid integer input.\n");
        return;
    }

    printf("\n");
    printf("========================================\n");
    printf("           ANALYSIS REPORT\n");
    printf("========================================\n");
    printf("Input number: %" PRId64 "\n", number);

    if (number < 2) {
        printf("Classification: NOT PRIME\n");
        printf("Reason: Prime numbers must be greater than 1.\n");
    } else {
        bool result = is_prime((uint64_t)number);

        if (result) {
            printf("Classification: PRIME\n");
        } else {
            printf("Classification: COMPOSITE\n");
        }
    }

    printf("========================================\n\n");
}

static void batch_analysis(void)
{
    int64_t count;
    int64_t number;
    int64_t i;
    int64_t prime_count = 0;
    int64_t composite_count = 0;
    int64_t other_count = 0;

    if (read_integer(
            "How many numbers do you want to analyze? ",
            &count) != STATUS_OK ||
        count < 1 ||
        count > 1000) {

        printf("[ERROR] Enter a quantity between 1 and 1000.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        char prompt[64];

        snprintf(
            prompt,
            sizeof(prompt),
            "Number %" PRId64 ": ",
            i + 1
        );

        if (read_integer(prompt, &number) != STATUS_OK) {
            printf("[ERROR] Invalid input. This entry was skipped.\n");
            other_count++;
            continue;
        }

        if (number < 2) {
            other_count++;
            continue;
        }

        if (is_prime((uint64_t)number)) {
            prime_count++;
        } else {
            composite_count++;
        }
    }

    printf("\n");
    printf("========================================\n");
    printf("              BATCH REPORT\n");
    printf("========================================\n");
    printf("Requested entries : %" PRId64 "\n", count);
    printf("Prime numbers     : %" PRId64 "\n", prime_count);
    printf("Composite numbers : %" PRId64 "\n", composite_count);
    printf("Other/invalid     : %" PRId64 "\n", other_count);
    printf("========================================\n\n");
}

static void divisor_analysis(void)
{
    int64_t number;
    int64_t divisor;
    int64_t total = 0;

    if (read_integer(
            "Enter an integer between 1 and 1000000: ",
            &number) != STATUS_OK ||
        number < 1 ||
        number > 1000000) {

        printf("[ERROR] Number outside the allowed range.\n");
        return;
    }

    printf("\nDivisors of %" PRId64 ":\n", number);

    for (divisor = 1; divisor <= number; divisor++) {
        if (number % divisor == 0) {
            printf("%" PRId64 " ", divisor);
            total++;
        }
    }

    printf("\nTotal divisors: %" PRId64 "\n", total);

    if (total == 2) {
        printf("Conclusion: The number is prime.\n");
    } else {
        printf("Conclusion: The number is not prime.\n");
    }

    printf("\n");
}

static void show_menu(void)
{
    printf("========================================\n");
    printf("       %s\n", APP_NAME);
    printf("                Version %s\n", APP_VERSION);
    printf("========================================\n");
    printf("1. Analyze a number\n");
    printf("2. Batch analysis\n");
    printf("3. Display divisors\n");
    printf("0. Exit\n");
    printf("========================================\n");
}

int main(void)
{
    int64_t option;

    while (true) {
        show_menu();

        if (read_integer("Select an option: ", &option) != STATUS_OK) {
            printf("\n[ERROR] Please enter a valid menu option.\n\n");
            continue;
        }

        switch (option) {
            case 1:
                analyze_number();
                break;

            case 2:
                batch_analysis();
                break;

            case 3:
                divisor_analysis();
                break;

            case 0:
                printf("\nClosing %s...\n", APP_NAME);
                printf("Thank you for using the application.\n");
                return EXIT_SUCCESS;

            default:
                printf("\n[ERROR] Option not recognized.\n\n");
                break;
        }
    }
}