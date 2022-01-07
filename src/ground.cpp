#include "ogre_demo.h"

void MyTestApp::create_ground(SceneManager *scene) {

  // create plane
  Plane plane(Vector3::UNIT_Y, 0);

  // create mesh
  MeshManager::getSingleton().createPlane("ground", RGN_DEFAULT, plane, 1500,
                                          1500, 20, 20, true, 1, 5, 5,
                                          Vector3::UNIT_Z);


  // create entity using generated mesh
  Entity *groundEntity = scene->createEntity("ground");
  scene->getRootSceneNode()->createChildSceneNode()->attachObject(
      groundEntity);

  // the ground doesn't need to cast shadows
  groundEntity->setCastShadows(false);

  // give the ground a material 
  groundEntity->setMaterialName("Examples/Rockwall");
  
}