#include "ogre_demo.h"

Light* MyTestApp::setup_lighting(SceneManager *scene, SceneNode *root_node){

    // without light we would just get a black screen
  Light *light = scene->createLight("MainLight");
  SceneNode *light_node = root_node->createChildSceneNode();
  light_node->setPosition(20, 80, 50);
  light_node->attachObject(light);

  return light;
}