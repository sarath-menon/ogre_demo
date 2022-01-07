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

  // create ground
  this->create_ground(scene);

  // Create entities [ogre keeps only one copy of mesh in memory, so two objects
  // of same mesh ok]
  Entity *ninjaEntity = scene->createEntity("ogrehead.mesh");

  // enable shadows
  ninjaEntity->setCastShadows(true);

  // Attace entities to scene
  SceneNode *node_2 = root_node->createChildSceneNode(Vector3(0, 0, 0));
  node_2->attachObject(ninjaEntity);
  node_2->roll(Degree(45));
}