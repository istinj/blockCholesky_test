//
// Created by istin on 03/03/17.
//

#include "SparseMatrix.h"
using namespace std;
using namespace Eigen;

SparseMatrix::SparseMatrix(int dim_rows,
                           int dim_cols){
    if(dim_rows % 6 != 0){
        cerr << "Total coloums are wrong" << endl;
        return;
    }
    if(dim_cols % 6 != 0){
        cerr << "Total rows are wrong" << endl;
        return;
    }

    _num_horz_block = dim_rows / 6;
    _num_vert_block = dim_cols / 6;
    cout << _num_horz_block << "\t" << _num_vert_block << endl;
    }
}

void SparseMatrix::initializeMatrix(int num_dense_block){
	if(num_dense_block % 2 != 0){
		cerr << "block number must be even because it is a symmetric sparse matrix" << endl;
		return;
	}

    DenseBlock6f block;
    for (int i = 0; i < num_dense_block; ++i) {
        Matrix6f temp_matrix = Matrix6f::Random();
        Matrix6f pd_matrix = temp_matrix.transpose() * temp_matrix;

        Vector2f indices = idx_generator(_num_horz_block, _num_vert_block);
//        cout << (Vector2f)indices.transpose() << endl;

//        _data.push_back(block);
    }
}

Eigen::Vector2f SparseMatrix::idx_generator(int num_h_blocks, int num_v_blocks){
    BoostRNG rng_h;
    boost::uniform_int<> row_idx_uniform(0, num_h_blocks);
    boost::variate_generator<BoostRNG, boost::uniform_int<>> row_idx_gen(rng_h, row_idx_uniform);
    int row_idx =  row_idx_gen();
    cout << "row_idx = " << row_idx << endl;

    BoostRNG rng_v;
    //! Must be a symetric matrix, thus we generate a upper triangular matrix and then we copy the entries
    boost::uniform_int<> col_idx_uniform(row_idx, num_v_blocks);
    boost::variate_generator<BoostRNG, boost::uniform_int<>> col_idx_gen(rng_v, col_idx_uniform);
    int col_idx = col_idx_gen();
    cout << "col_idx = " << col_idx << endl;

    return Vector2f(row_idx, col_idx);
}
