#include "ogre_demo.h"

void MyTestApp::setup_camera(SceneManager *scene, SceneNode *root_node) {

  // create camera so we can observe scene
  Camera *camera = scene->createCamera("MainCamera");
  camera->setNearClipDistance(5); // specific to this sample
  camera->setAutoAspectRatio(true);

  SceneNode *camera_node = root_node->createChildSceneNode();
  camera_node->setPosition(0, 0, 250);
  camera_node->lookAt(Vector3{0, 0, -1}, Node::TS_PARENT);
  camera_node->attachObject(camera);

  // render into the main window
  getRenderWindow()->addViewport(camera);
}