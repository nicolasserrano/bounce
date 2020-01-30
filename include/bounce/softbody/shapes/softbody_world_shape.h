/*
* Copyright (c) 2016-2019 Irlan Robson https://irlanrobson.github.io
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef B3_SOFTBODY_WORLD_SHAPE_H
#define B3_SOFTBODY_WORLD_SHAPE_H

#include <bounce/softbody/shapes/softbody_shape.h>
#include <bounce/collision/shapes/aabb.h>
#include <bounce/common/template/list.h>

class b3Shape;

struct b3SoftBodyWorldShapeDef
{
	const b3Shape* shape;
};

class b3SoftBodyWorldShape : public b3SoftBodyShape
{
public:
private:
	friend class b3SoftBody;
	friend class b3SoftBodyContactManager;
	friend class b3SoftBodyContactSolver;
	friend class b3SoftBodySphereAndShapeContact;
	friend class b3List2<b3SoftBodyWorldShape>;
	
	b3SoftBodyWorldShape() { }
	~b3SoftBodyWorldShape() { }

	// Compute AABB
	b3AABB ComputeAABB() const;

	// Synchronize AABB
	void Synchronize(const b3Vec3& displacement);

	// Destroy contacts
	void DestroyContacts();

	const b3Shape* m_shape;
	
	b3SoftBodyWorldShape* m_prev;
	b3SoftBodyWorldShape* m_next;
};

#endif