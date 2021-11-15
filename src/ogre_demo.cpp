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

void MyTestApp::setup(void) {
  // do not forget to call the base first
  OgreBites::ApplicationContext::setup();

  // register for input events
  addInputListener(this);

  // get a pointer to the already created root
  Ogre::Root *root = getRoot();
  Ogre::SceneManager *scnMgr = root->createSceneManager();

  // register our scene with the RTSS
  Ogre::RTShader::ShaderGenerator *shadergen =
      Ogre::RTShader::ShaderGenerator::getSingletonPtr();
  shadergen->addSceneManager(scnMgr);

  // without light we would just get a black screen
  Ogre::Light *light = scnMgr->createLight("MainLight");
  Ogre::SceneNode *lightNode =
      scnMgr->getRootSceneNode()->createChildSceneNode();

  // Set light position
  lightNode->setPosition(0, 10, 15);
  lightNode->attachObject(light);

  // also need to tell where we are
  Ogre::SceneNode *camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  camNode->setPosition(0, 0, 15);
  camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

  // create the camera
  Ogre::Camera *cam = scnMgr->createCamera("myCam");
  cam->setNearClipDistance(5); // specific to this sample
  cam->setAutoAspectRatio(true);
  camNode->attachObject(cam);

  // and tell it to render into the main window
  getRenderWindow()->addViewport(cam);

  // finally something to render
  Ogre::Entity *ent = scnMgr->createEntity("Sinbad.mesh");
  Ogre::SceneNode *node = scnMgr->getRootSceneNode()->createChildSceneNode();
  node->attachObject(ent);
}
