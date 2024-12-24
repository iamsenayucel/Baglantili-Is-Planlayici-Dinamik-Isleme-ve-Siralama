#include <stdio.h>

#define MAX 50

void printSchedule(int num, int head, char jobs[MAX][3], int times[MAX], int links[MAX]) {
    int i, j;
    int current = head;

    for (i = 0; i < num; i++) {
        for (j = 0; j < times[current]; j++) {   // her iþin adýný süresi kadar yazdýrma
            printf("%c ", jobs[current][0]);
        }
        current = links[current];               // sonraki iþin indeksini güncelleme
    }
    printf("\n");
}

int main() {
    char jobs[MAX][3];
    int times[MAX], links[MAX], head, i, num;

    printf("is sayisi: ");
    scanf("%d", &num);

    if (num > MAX) {
        printf("Hata: Daha dusuk bir is sayisi giriniz!\n");
        return 1;
    }
    
    printf("islerin bilgilerini giriniz:\n");

    for (i = 0; i < num; i++) {
        printf("%d. is kodu: ", i + 1);
        scanf(" %c", &jobs[i][0]);

        // Ýþ kodu kontrolü
        int j;
        for ( j = 0; j < i; j++) {
            if (jobs[i][0] == jobs[j][0]) {
                printf("Hata: farkli bir is kodu giriniz:\n");
                i--;
                break;
            }
        }

        printf("%d. isin tamamlanma suresi: ", i + 1);
        scanf("%d", &times[i]);

        printf("%d. isin link sirasi: ", i + 1);
        scanf("%d", &links[i]);
    }

    printf("head degeri: ");
    scanf("%d", &head);

    printf("MATRIS: HEAD:%d\n", head);
    for (i = 0; i < num; i++) {                                      // iþleri matris þeklinde yazdýrma
        printf("%c %d %d\n", jobs[i][0], times[i], links[i]);
    }

    printf("OUTPUT: ");
    printSchedule(num, head, jobs, times, links);

    return 0;
}

