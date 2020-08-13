//
// Created by chudonghao on 2020/8/9.
//

#include "Viewer.h"

#include <osgDB/Registry>
#include <osgEarth/MapNode>
#include <osgEarth/MapNodeOptions>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/MouseCoordsTool>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>

#include <cdhGame/runtime/App.h>

class Print : public osgEarth::Util::MouseCoordsTool::Callback {
public:
  void set(const osgEarth::GeoPoint &coords, osg::View *view, osgEarth::MapNode *mapNode) override { APP_LOG_INFO << coords.x() << ' ' << coords.y() << ' ' << coords.z(); }
  void reset(osg::View *view, osgEarth::MapNode *mapNode) override {}
};

using namespace cdh3d;

Viewer::Viewer() {
  _databaseOptions = new osgDB::Options;
  // map node
  osgEarth::MapOptions opts;
  opts.coordSysType() = osgEarth::MapOptions::CSTYPE_PROJECTED;
  opts.profile()->bounds() = osgEarth::Bounds(-4000, -4000, 4000, 4000);
  _mapNode = new osgEarth::MapNode(new osgEarth::Map(opts));
  APP_LOG_INFO << _mapNode->getMapSRS()->getName();
  setSceneData(_mapNode);
  // earth manipulator
  setCameraManipulator(new osgEarth::Util::EarthManipulator);
  auto mct = new osgEarth::Util::MouseCoordsTool(_mapNode);
  mct->addCallback(new Print);
  addEventHandler(mct);
  addEventHandler(new osgGA::StateSetManipulator(getSceneData()->getOrCreateStateSet()));
  addEventHandler(new osgViewer::StatsHandler);
}
int Viewer::loadPlayground() {
  std::string defaultSceneFile = osgDB::Registry::instance()->findDataFile("1.txt", _databaseOptions, osgDB::CaseSensitivity::CASE_SENSITIVE);
  return 0;
}
void Viewer::setDatabaseOptions(osgDB::Options *dbOpts) { _databaseOptions = dbOpts; }
