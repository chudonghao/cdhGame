//
// Created by chudonghao on 2020/8/9.
//

#ifndef CDHGAME_D717CE65AE4841B38BD31F604AD762F6_
#define CDHGAME_D717CE65AE4841B38BD31F604AD762F6_

#include <osgDB/Options>
#include <osgViewer/Viewer>
#include <osgEarth/MapNode>

namespace cdh3d {

class Viewer : public osgViewer::Viewer {
public:
  Viewer();
  void setDatabaseOptions(osgDB::Options *dbOpts);
  int loadPlayground();

private:
  osg::ref_ptr<osgDB::Options> _databaseOptions{};
  osg::ref_ptr<osgEarth::MapNode> _mapNode;
};

} // namespace cdh3d

#endif // CDHGAME_D717CE65AE4841B38BD31F604AD762F6_
