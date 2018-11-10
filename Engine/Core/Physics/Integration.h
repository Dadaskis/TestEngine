#ifndef ENGINE_PHYSICS_INTEGRATION_INCLUDE
#define ENGINE_PHYSICS_INTEGRATION_INCLUDE

namespace Engine{

namespace Physics{

namespace World{

using Discrete = btDiscreteDynamicWorld; 
using Simple = btSimpleDynamicWorld;
using Base = btDynamicsWorld;

};

namespace Broadphase{

using Base = btBroadphase;
using DBVT = btDbvtBroadphase;
using AxisSweep = btAxisSweep3;
using 32bitAxisSweep = bt32BitAxisSweep3;
using Bruteforce = btSimpleBroadphase;

};

namespace Solver{

using btSolver

};

namespace 

};

};

#endif