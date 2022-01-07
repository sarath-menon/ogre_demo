#pragma once

#include <Ogre.h>
#include <OgreApplicationContext.h>

using namespace Ogre;

// ApplicationContext, -> Use inbuild simple gui system
// Inputlistener -> Handle inputs

class MyTestApp : public OgreBites::ApplicationContext,
                  public OgreBites::InputListener {
public:
  MyTestApp();
  ~MyTestApp() {}

  SceneManager* setup_scene();
  void setup_lighting(SceneManager *scene, SceneNode *root_node);
  void setup_camera(SceneManager *scene, SceneNode *root_node);
  void create_ground(SceneManager *scene);

  void setup() override;
  bool keyPressed(OgreBites::KeyboardEvent const &evt) override;
};
