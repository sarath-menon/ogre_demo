#include "ogre_demo.h"

// Specify app name
MyTestApp::MyTestApp() : OgreBites::ApplicationContext{"OgreTutorialApp"} {}

// Close window when esc key pressed
bool MyTestApp::keyPressed(OgreBites::KeyboardEvent const &evt) {
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
    return true;
  } else
    return false; // key not processed
}

void MyTestApp::setup() {
  OgreBites::ApplicationContext::setup();
  addInputListener(this); // register for input events

  auto scene = this->setup_scene();

  SceneNode *root_node = scene->getRootSceneNode();

  this->setup_lighting(scene, root_node);

  this->setup_camera(scene, root_node);

  // Create entities [ogre keeps only one copy of mesh in memory, so two objects
  // of same mesh ok]
  Entity *obj_1 = scene->createEntity("ogrehead.mesh");
  Entity *obj_2 = scene->createEntity("ogrehead.mesh");

  // Attace entities to scene
  SceneNode *node_1 = root_node->createChildSceneNode();
  SceneNode *node_2 = root_node->createChildSceneNode(Vector3(84, 48, 0));

  node_1->attachObject(obj_1);
  node_2->attachObject(obj_2);
}