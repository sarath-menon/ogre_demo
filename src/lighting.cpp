#include "ogre_demo.h"

void MyTestApp::setup_lighting(SceneManager *scene, SceneNode *root_node) {

  // set the ambient lighting
  scene->setAmbientLight(ColourValue{0.1, 0.5, 0.5});

  // without light we would just get a black screen
  Light *light = scene->createLight("MainLight");
  SceneNode *light_node = root_node->createChildSceneNode();

  // attach light to node in scene
  light_node->setPosition(20, 80, 50);
  light_node->attachObject(light);
}