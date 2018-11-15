#ifndef ENGINE_PHYSICS_INTEGRATION_INCLUDE
#define ENGINE_PHYSICS_INTEGRATION_INCLUDE

namespace Engine{

namespace Physics{

namespace World{

using Discrete = btDiscreteDynamicsWorld; 
using Simple = btSimpleDynamicsWorld;
using Base = btDynamicsWorld;

};

namespace Broadphase{

using Base = btBroadphaseInterface;
using DBVT = btDbvtBroadphase;
using AxisSweep = btAxisSweep3;
using Bruteforce = btSimpleBroadphase;

};

namespace Solver{

using Base = btConstraintSolver;
using SequentialImpulse = btSequentialImpulseConstraintSolver; 

};

namespace Shape{

using TriangleMeshData = btTriangleMesh;
using Box = btBoxShape;
using Sphere = btSphereShape;
using TriangleMeshDynamic = btGImpactMeshShape;
using TriangleMeshStatic = btBvhTriangleMeshShape;
using DynamicTriangleMeshAlgorithm = btGImpactCollisionAlgorithm;

};
  
namespace Collision{
  
using Shape = btCollisionShape;

namespace Config{
  
using Base = btCollisionConfiguration;
using Default = btDefaultCollisionConfiguration;
  
};

namespace Broadphase{
  
using Base = btBroadphaseInterface;
using DBVT = btDbvtBroadphase;
  
};

namespace Dispatcher{
  
using Base = btCollisionDispatcher;
  
};
  
};
  
namespace MotionState{
  
using Base = btMotionState;
using Default = btDefaultMotionState;
  
};
  
};

};

#endif
