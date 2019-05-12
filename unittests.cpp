//
// Created by oleg on 05.05.19.
//

#include "points_sequence.h"
#include "cmath"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST (GettingLength, IntegerLength) {
    points_sequence seq;
    seq.points.resize(4);
    seq.points[0] = {0, 0};
    seq.points[1] = {0, 1};
    seq.points[2] = {0, 2};
    seq.points[3] = {0, 3};
    ASSERT_NEAR(6, seq.get_length(), 0.0001);
}

TEST (GettingLength, DoubleLength) {
    points_sequence seq;
    seq.points.resize(4);
    seq.points[0] = {0, 0};
    seq.points[1] = {1, 1};
    seq.points[2] = {2, 2};
    seq.points[3] = {3, 3};
    ASSERT_NEAR(6*sqrt(2), seq.get_length(), 0.0001);
}

TEST (SettingLengthMinimal, SortedSequence) {
    points_sequence seq;
    seq.points.resize(4);
    seq.points[0] = {0, 0};
    seq.points[1] = {1, 1};
    seq.points[2] = {2, 2};
    seq.points[3] = {3, 3};
    seq.minimize_length();
    ASSERT_NEAR(6*sqrt(2), seq.get_length(), 0.0001);
}

TEST (SettingLengthMinimal, UnsortedSequence) {
    points_sequence seq;
    seq.points.resize(4);
    seq.points[0] = {0, 0};
    seq.points[1] = {2, 2};
    seq.points[2] = {1, 1};
    seq.points[3] = {3, 3};
    seq.minimize_length();
    ASSERT_NEAR(6*sqrt(2), seq.get_length(), 0.0001);
}
