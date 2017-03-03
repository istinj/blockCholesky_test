//
// Created by istin on 03/03/17.
//
#ifndef BLOCKCHOL_SPARSEMATRIX_H
#define BLOCKCHOL_SPARSEMATRIX_H
#pragma once

#include <iostream>
#include <vector>
#include <Eigen/Core>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>

typedef Eigen::Matrix<float, 6, 6> Matrix6f;
typedef std::pair<Eigen::Vector2f, Eigen::Matrix<float, 6, 6>> DenseBlock6f;
typedef std::vector<DenseBlock6f> PackedSparse;
typedef boost::mt19937 BoostRNG;

class SparseMatrix {
public:
	SparseMatrix() = delete;
    SparseMatrix(int dim_rows, int dim_cols); //! CTOR
    ~SparseMatrix(); //! DTOR
    void initializeMatrix(int num_dense_block);

private:
    Eigen::Vector2f idx_generator(int num_h_blocks, int num_v_blocks);

    int _num_horz_block = -1;
    int _num_vert_block = -1;
    PackedSparse _data;

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
};


#endif //BLOCKCHOL_SPARSEMATRIX_H
