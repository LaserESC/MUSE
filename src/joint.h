/* ----------------------------------------------------------------------
   MUSE - MUltibody System dynamics Engine

   Zhang He, zhanghecalt@163.com
   Science and Technology on Space Physics Laboratory, Beijing

   This software is distributed under the GNU General Public License.
   Copyright (c) 2023 Zhang He. All rights reserved.
------------------------------------------------------------------------- */

#ifndef MUSE_JOINT_H
#define MUSE_JOINT_H

#define QUATERR 1E-8
#define NORMERR 1E-3

#include "pointers.h"
#include "body.h"
#include "MUSEsystem.h"
#include "Eigen/Eigen"
namespace MUSE_NS {

class Joint : protected Pointers {
public:

    char *name;
	
	Eigen::Vector3d axis1;
	Eigen::Vector3d axis2;
	Eigen::Vector3d point1;
	Eigen::Vector3d point2;

	Body *body[2];
	System * mySystem;
	int IDinSystem;
	int IDinMuse;

	Eigen::MatrixXd A1;
	Eigen::MatrixXd A2;
	Eigen::VectorXd b;

	
	void constrainteq_sphere();
	void constrainteq_ground();
	typedef void (Joint::* FnPtr)();
	FnPtr consptr;
	
	void runconstrainteq();


	Joint(class MUSE *);
	~Joint();

	void set_Name(char*);
	void set_type(int);
	void set_type_by_name(char*);
	void set_axis(double, double, double, int);
	int get_type();

private:
	int type;

};

}

#endif