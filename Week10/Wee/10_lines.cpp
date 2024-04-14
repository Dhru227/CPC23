#include <iostream>
#include <cstring>

#define DELIM '\n' 

void print_last_lines(const char *str, int n) 
{ 
    if (n <= 0) 
        return; 

    size_t cnt = 0; 
    const char *target_pos = nullptr; 

    target_pos = strrchr(str, DELIM); 

    if (target_pos == nullptr) 
    { 
        std::cout << "ERROR: string doesn't contain '\\n' character\n"; 
        return; 
    } 

    while (cnt < n) 
    { 
        while (str < target_pos && *target_pos != DELIM) 
            --target_pos; 

        if (*target_pos == DELIM) 
            --target_pos, ++cnt; 
        else
            break; 
    } 

    if (str < target_pos) 
        target_pos += 2; 

    std::cout << target_pos << std::endl; 
} 

int main(void) 
{ 
    const char *str1 ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                    "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                    "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25"; 
    const char *str2 ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7"; 
    const char *str3 ="\n"; 
    const char *str4 = ""; 

    print_last_lines(str1, 10); 
    std::cout << "-----------------\n"; 

    print_last_lines(str2, 10); 
    std::cout << "-----------------\n";

    print_last_lines(str3, 10); 
    std::cout << "-----------------\n"; 

    print_last_lines(str4, 10); 
    std::cout << "-----------------\n";

    return 0; 
} 
