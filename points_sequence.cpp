//
// Created by oleg on 05.05.19.
//

#include "points_sequence.h"

void points_sequence::read_points() {
    int size;
    printf("Введите количество точек\n");
    scanf("%d", &size);
    points.resize(size);
    printf("Введите координаты точек\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d %d", &(points[i].first), &(points[i].second));
    }
}

double points_sequence::get_length() {
    double ans = 0;
    for (int i = 0; i < points.size()-1; ++i) {
        ans += get_dist(points[i], points[i+1]);
    }
    ans += get_dist(points[points.size() - 1], points[0]);
    return ans;
}

void points_sequence::minimize_length() {
    std::vector <int> used (points.size(), false);
    std::vector <std::pair<int, int> > current_sequence(1), best_sequence(points.size());
    used[0] = true;
    current_sequence[0] = points[0];
    double best_length = -1, current_length = 0;
    add_next(current_sequence, best_sequence, used, current_length, best_length);
    for (int i = 0; i < best_sequence.size(); i++) points[i] = best_sequence[i];
}

void points_sequence::add_next(std::vector <std::pair <int, int> > &current_sequence,
                               std::vector <std::pair <int, int> > &best_sequence,
                               std::vector <int> &used,
                               double &current_length,
                               double &best_length) {
    if (current_sequence.size() == points.size()) {
        double last_length = current_length;
        current_length += get_dist(points[0], current_sequence[current_sequence.size() - 1]);
        if ((best_length < -0.5) || (current_length < best_length))
        {
            for (int i = 0; i < current_sequence.size(); ++i) best_sequence[i] = current_sequence[i];
            best_length = current_length;
        }
        current_length = last_length;
    }

    else for (int i = 0; i < points.size(); i++) {
            if (used[i] == false) {
                double last_length = current_length;
                current_length += get_dist(points[i], current_sequence[current_sequence.size() - 1]);
                current_sequence.push_back(points[i]);
                used[i] = true;
                add_next(current_sequence, best_sequence, used, current_length, best_length);
                used[i] = false;
                current_length = last_length;
                current_sequence.pop_back();
            }
        }
}

double points_sequence::get_dist(std::pair<int, int> first_point, std::pair<int, int > second_point) {
    return sqrt((first_point.first - second_point.first) * (first_point.first - second_point.first) +
                (first_point.second - second_point.second) * (first_point.second - second_point.second));
}