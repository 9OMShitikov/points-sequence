//
// Created by oleg on 05.05.19.
//

#ifndef UNTITLED_POINTS_SEQUENCE_H
#define UNTITLED_POINTS_SEQUENCE_H

#include <vector>
#include <stdio.h>
#include <cmath>
class points_sequence {
public:
    std::vector <std::pair<int, int> > points;

    void read_points();

    void minimize_length();

    double get_length();
private:
    void add_next(std::vector <std::pair <int, int> > &current_sequence,
                  std::vector <std::pair <int, int> > &best_sequence,
                  std::vector <int> &used,
                  double &current_length,
                  double &best_length);

    double get_dist(std::pair<int, int> first_point, std::pair<int, int > second_point);
};

#endif //UNTITLED_POINTS_SEQUENCE_H
