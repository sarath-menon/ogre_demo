#include "ogre_demo.h"

void MyTestApp::setup_lighting(SceneManager *scene, SceneNode *root_node) {

  // set the ambient lighting
  scene->setAmbientLight(ColourValue{0.1, 0.5, 0.5});

  // turn off ambient lighting to see full effect of custom lights
  scene->setAmbientLight(ColourValue(0, 0, 0));
  // enable shadows in the scene
  scene->setShadowTechnique(ShadowTechnique::SHADOWTYPE_STENCIL_ADDITIVE);

  //! [spotlight]
    Light* spotLight = scene->createLight("SpotLight");
    //! [spotlight]

    //! [spotlightcolor]
    spotLight->setDiffuseColour(0, 0, 1.0);
    spotLight->setSpecularColour(0, 0, 1.0);
    //! [spotlightcolor]

    //! [spotlighttype]
    spotLight->setType(Light::LT_SPOTLIGHT);
    //! [spotlighttype]

    //! [spotlightposrot]
    SceneNode* spotLightNode = scene->getRootSceneNode()->createChildSceneNode();
    spotLightNode->attachObject(spotLight);
    spotLightNode->setDirection(-1, -1, 0);
    spotLightNode->setPosition(Vector3(200, 200, 0));
    //! [spotlightposrot]

    //! [spotlightrange]
    spotLight->setSpotlightRange(Degree(35), Degree(50));
    //! [spotlightrange]

    //! [directlight]
    Light* directionalLight = scene->createLight("DirectionalLight");
    directionalLight->setType(Light::LT_DIRECTIONAL);
    //! [directlight]

    //! [directlightcolor]
    directionalLight->setDiffuseColour(ColourValue(0.4, 0, 0));
    directionalLight->setSpecularColour(ColourValue(0.4, 0, 0));
    //! [directlightcolor]

    //! [directlightdir]
    SceneNode* directionalLightNode = scene->getRootSceneNode()->createChildSceneNode();
    directionalLightNode->attachObject(directionalLight);
    directionalLightNode->setDirection(Vector3(0, -1, 1));
    //! [directlightdir]

    //! [pointlight]
    Light* pointLight = scene->createLight("PointLight");
    pointLight->setType(Light::LT_POINT);
    //! [pointlight]

    //! [pointlightcolor]
    pointLight->setDiffuseColour(0.3, 0.3, 0.3);
    pointLight->setSpecularColour(0.3, 0.3, 0.3);
    //! [pointlightcolor]

    //! [pointlightpos]
    SceneNode* pointLightNode = scene->getRootSceneNode()->createChildSceneNode();
    pointLightNode->attachObject(pointLight);
    pointLightNode->setPosition(Vector3(0, 150, 250));
}