#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct page{
    int number_of_page;
    int r_bit;
    int bits;
    int clock;
};

bool existing_of_page(struct page pages[], int number, int n){
    for (int i = 0; i < n; ++i){
        if (pages[i].number_of_page == number){
            return 1;
        }
    }
    return 0;
}

int find_recently_used_page(struct page pages[], int n){
    int small = INT_MAX;
    int small_i = -1;
    for (int i = 0; i < n; i++) {
        if (pages[i].bits < small) {
            small = pages[i].bits;
            small_i = i;
        }
    }
    return small_i;
}

int main() {
    int n, m, a, t;
    int hits = 0;
    int misses = 0;
    double ratio = 0;
    scanf("%d %d", &n, &m);
    struct page all_pages[m];
    struct page pf[n];

    for (int i = 0; i < m; ++i){
        scanf("%d %d", &t, &a);
        all_pages[i].bits = 0;
        all_pages[i].r_bit = 0;
        all_pages[i].number_of_page = a;
        all_pages[i].clock = t;
    }

    pf[0] = all_pages[0];
    printf("0\n");
    misses++;
    for (int i = 1; i < m; ++i){
        if (all_pages[i].clock == all_pages[i-1].clock) {
            if (i < n) {
                pf[i] = all_pages[i];
                all_pages[i].r_bit = 0;
                misses ++;
                printf("0\n");
            } else if (existing_of_page(pf, all_pages[i].number_of_page, n)){
                hits++;
                all_pages[i].r_bit = 1;
                printf("1\n");
            } else {
                int j = find_recently_used_page(pf, n);
                pf[j] = all_pages[i];
                misses++;
                all_pages[i].r_bit = 1;
                all_pages[i].bits = 0;
                printf("0\n");
            }
        } else {
            for (int j = 0; j < i; ++j){
                pf[j].bits = pf[i].bits = (pf[i].bits >> 1)|(pf[i].r_bit<<7);
                pf[j].r_bit = 0;
            }
            if (existing_of_page(pf, all_pages[i].number_of_page, n)){
                all_pages[i].r_bit = 1;
                hits ++;
                printf("1\n");
            } else {
                int k = find_recently_used_page(pf, n);
                pf[k] = all_pages[i];
                all_pages[i].r_bit = 1;
                all_pages[i].bits = 0;
                misses++;
                printf("0\n");
            }
        }
    }

    ratio = (double)hits/(double)misses;
    printf("%f\n", ratio);
    return 0;
}
