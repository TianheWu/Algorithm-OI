#include <bits/stdc++.h>
using namespace std;

int chinese_room_num = 20, english_room_num = 20;
int chinese_room_order[98];
int english_room_order[98];

struct Classroom {
    int sum_number = 20;
    int order[20];
};

struct Students {
    int chinese_interview_room_num;
    int chinese_interview_order;
    int english_interview_room;
    int english_interview_order;
    int question_index;
};

Students students[98];

int get_random_num(int min_val, int max_val) {
    srand((unsigned) time(NULL));
    int random_num = rand() % (max_val - min_val + 1) + min_val;
    return random_num;
}

int main() {
    
}