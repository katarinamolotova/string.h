#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *s = s21_NULL;
    if (src != s21_NULL && str != s21_NULL) {
        s21_size_t len_src = s21_strlen(src), len_str = s21_strlen(str), new_len = len_src + len_str;
        s = (char *)malloc((new_len + 1) * sizeof(char));
        if (len_str == 0) {
            for (s21_size_t i = 0; i <= len_src; i++) {
                s[i] = src[i];
            }
        } else {
            s21_size_t x = 0, y = 0, i = 0;
            while (i < new_len) {
                if (i < start_index) {
                    while (i < start_index) {
                        s[i] = src[i];
                        i++;
                    }
                    x = i;
                } else if (i == start_index) {
                    while (y < len_str) {
                        s[i] = str[y];
                        i++;
                        y++;
                    }
                } else {
                    while (x < len_src) {
                        s[i] = src[x];
                        x++;
                        i++;
                    }
                }
            }
            s[i] = '\0';
        }
    }
    return s;
}
