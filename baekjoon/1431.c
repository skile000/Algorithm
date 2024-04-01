#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Pair {
    char first[51];
    int second;
};

typedef struct Pair Pair;

Pair v[1001];

int compare(const void *a, const void *b) {
    Pair *pa = (Pair *)a;
    Pair *pb = (Pair *)b;

    if (strlen(pa->first) == strlen(pb->first)) {
        if (pa->second == pb->second) {
            return strcmp(pa->first, pb->first);
        }
        else {
            return (pa->second - pb->second);
        }
    }
    else {
        return (strlen(pa->first) - strlen(pb->first));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char s[51];
        int total = 0;
        scanf("%s", s);
        for (int j = 0; s[j] != '\0'; j++) {
            if ('0' <= s[j] && s[j] <= '9') {
                total += s[j] - '0';
            }
        }
        strcpy(v[i].first, s);
        v[i].second = total;
    }

    qsort(v, n, sizeof(Pair), compare);

    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i].first);
    }
    return 0;
}