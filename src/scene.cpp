#include "ogre_demo.h"

SceneManager* MyTestApp::setup_scene(){

  SceneManager *scene = getRoot()->createSceneManager();
 

  // register our scene with the RTSS
  RTShader::ShaderGenerator *shadergen =
      RTShader::ShaderGenerator::getSingletonPtr();
  shadergen->addSceneManager(scene);

  return scene;

}