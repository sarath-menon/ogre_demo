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

  SceneManager *scene = getRoot()->createSceneManager();
  scene->setAmbientLight(ColourValue{0.5, 0.5, 0.5});

  // register our scene with the RTSS
  RTShader::ShaderGenerator *shadergen =
      RTShader::ShaderGenerator::getSingletonPtr();
  shadergen->addSceneManager(scene);

  SceneNode *root_node = scene->getRootSceneNode();

  // without light we would just get a black screen
  Light *light = scene->createLight("MainLight");
  SceneNode *light_node = root_node->createChildSceneNode();
  light_node->setPosition(20, 80, 50);
  light_node->attachObject(light);

  // create camera so we can observe scene
  Camera *camera = scene->createCamera("MainCamera");
  camera->setNearClipDistance(5); // specific to this sample
  camera->setAutoAspectRatio(true);
  SceneNode *camera_node = root_node->createChildSceneNode();
  camera_node->setPosition(0, 0, 250);
  camera_node->lookAt(Vector3{0, 0, -1}, Node::TS_PARENT);
  camera_node->attachObject(camera);

  getRenderWindow()->addViewport(camera); // render into the main window

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