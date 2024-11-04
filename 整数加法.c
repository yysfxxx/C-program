#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addLargeNumbers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2)? len1 : len2;
    int carry = 0;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0)? num1[i] - '0' : 0;
        int digit2 = (j >= 0)? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k++] = (sum % 10) + '0';
        i--;
        j--;
    }
    result[k] = '\0';
    // 反转结果字符串
    int left = 0;
    int right = k - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }
    return result;
}

int main() {
    char num1[1000];
    char num2[1000];
    scanf("%s %s", num1, num2);
    char* sum = addLargeNumbers(num1, num2);
    printf("%s\n", sum);
    free(sum);
    return 0;
}
