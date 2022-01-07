#include "ogre_demo.h"


void MyTestApp::addResourceDirectory(const std::string &dir) {
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(dir,
                                                                 "FileSystem",
                                                                 Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                                                 false,
                                                                 true);
  // Initialise the resource groups:
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void MyTestApp::loadMaterialFile(const std::string &filename) {
  Ogre::DataStreamPtr ds = Ogre::ResourceGroupManager::getSingleton().openResource(filename,
                                                                                   Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
  Ogre::MaterialManager::getSingleton().parseScript(ds, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
}