#include <iostream>

std::size_t strlen(const char *str) {
  int size = 0;
  for (; *str; ++str)
    if (*str != '\0') size++;
  return size;
}

char *str_rot13(char *str) {
  char *c = str;
  for (; *str; str++) {
    if (('a' <= *str && *str <= 'm') || ('A' <= *str && *str <= 'M'))
      *str += 13;
    else if (('n' <= *str && *str <= 'z') || ('N' <= *str && *str <= 'Z'))
      *str -= 13;
  }
  return c;
}

char *strrev(char *str) {
  int l = strlen(str);
  for (int i = 0; i < l/2; i++) {
    char c = str[l-i-1];
    str[l-i-1] = str[i];
    str[i] = c;
  }
  return str;
}

const char *strrchr(const char *haystack, const char needle) {
  for (int i = strlen(haystack); i > 0; i--)
    if (haystack[i] == needle) return (haystack + i);
  return nullptr;
}

int main() {

  char str[] = "hello";

  std::cout << static_cast<char>('h' + 13);
  std::cout << static_cast<char>('e' + 13);
  std::cout << static_cast<char>('l' + 13);
  std::cout << static_cast<char>('l' + 13);
  std::cout << static_cast<char>('o' - 13);
  std::cout << '\n';
  std::cout << str_rot13(str) << '\n';
}