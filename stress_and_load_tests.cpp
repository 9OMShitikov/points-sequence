//
// Created by oleg on 12.05.19.
//
#include "points_sequence.h"
#include "cmath"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST (Load_tests, ten_points) {
    points_sequence seq;
    int n = 10;
    seq.points.resize(n);
    for (int i = 0; i < n; i++) {seq.points[i] = {0,i};}
    seq.minimize_length();
    ASSERT_NEAR(2*(n-1), seq.get_length(), 0.0001);
}

TEST (Load_tests, eleven_points) {
    points_sequence seq;
    int n = 11;
    seq.points.resize(n);
    for (int i = 0; i < n; i++) {seq.points[i] = {0,i};}
    seq.minimize_length();
    ASSERT_NEAR(2*(n-1), seq.get_length(), 0.0001);
}


TEST (Stress_tests, twelve_points) {
    points_sequence seq;
    int n = 12;
    seq.points.resize(n);
    for (int i = 0; i < n; i++) {seq.points[i] = {0,i};}
    seq.minimize_length();
    ASSERT_NEAR(2*(n-1), seq.get_length(), 0.0001);
}

TEST (Stress_tests, thirteen_points) {
    points_sequence seq;
    int n = 13;
    seq.points.resize(n);
    for (int i = 0; i < n; i++) {seq.points[i] = {0,i};}
    seq.minimize_length();
    ASSERT_NEAR(2*(n-1), seq.get_length(), 0.0001);
}
