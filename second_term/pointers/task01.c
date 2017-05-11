#include <stdio.h>

#define MAX_MEETINGS 7
#define LIMIT_SALARY 1024.64
#define REMOTE_JOB_LIMIT_MEETINGS 4
#define OFFICE_JOB_LIMIT_MEETINGS 6

typedef struct job_offer_t {
    float salary;
    int is_remote;
    int meetings[MAX_MEETINGS];
} job_offer_t;

int get_sum(int*, int);
int accept_job_offer(job_offer_t);

int main() {
    job_offer_t offer = {
        .salary = 545.12,
        .is_remote = 0,
        .meetings = { 3, 0, 1, 0, 1, 0, 0 }
    };

    printf("%d\n", accept_job_offer(offer));

    offer.salary = LIMIT_SALARY;
    offer.is_remote = 1;
    offer.meetings[0] = 1;

    printf("%d\n", accept_job_offer(offer));

    offer.salary = LIMIT_SALARY + 1000;
    offer.meetings[0] = 5;

    printf("%d\n", accept_job_offer(offer));

    return 0;
}

int get_sum(int *arr, int size) {
    int result = 0;

    for (size_t i = 0; i < size; i++) {
        result += arr[i];
    }

    return result;
}

int accept_job_offer(job_offer_t offer) {
    int meetings = get_sum(offer.meetings, MAX_MEETINGS);

    if (offer.salary >= LIMIT_SALARY) {
        return (
            (offer.is_remote && meetings < REMOTE_JOB_LIMIT_MEETINGS) ||
            (!offer.is_remote && meetings < OFFICE_JOB_LIMIT_MEETINGS)
        );
    }

    return 0;
}
