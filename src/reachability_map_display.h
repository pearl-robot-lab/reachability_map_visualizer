#ifndef REACHABILITY_MAP_DISPLAY_H
#define REACHABILITY_MAP_DISPLAY_H

#ifndef Q_MOC_RUN

#include <rviz/message_filter_display.h>

#include <reachability_map_visualizer/WorkSpace.h>
#endif

namespace Ogre
{
class SceneNode;
}

namespace rviz
{
class EnumProperty;
class BoolProperty;
class ColorProperty;
class FloatProperty;
class IntProperty;
}

namespace reachability_map_visualizer
{
class ReachMapVisual;
class ReachMapDisplay : public rviz::MessageFilterDisplay< reachability_map_visualizer::WorkSpace >
{
  Q_OBJECT
public:
  enum Shape
  {
    Sphere,
    Cylinder,
    Cone,
    Cube,
  };

  enum Disect
  {
    Full,
    First_Half,
    Second_Half,
    Middle_Slice,
    End_Slice,
  };

  ReachMapDisplay();
  virtual ~ReachMapDisplay();

protected:
  virtual void onInitialize();
  virtual void reset();

private Q_SLOTS:
  void updateColorAndAlphaArrow();
  void updateArrowSize();

  void updateColorAndAlphaSphere();
  void updateSphereSize();

private:
  void processMessage(const reachability_map_visualizer::WorkSpace::ConstPtr& msg);
  std::vector< boost::shared_ptr< ReachMapVisual > > visuals_;

  rviz::Property* arrow_category_;
  rviz::Property* sphere_category_;

  rviz::BoolProperty* do_display_arrow_;
  rviz::ColorProperty* arrow_color_property_;
  rviz::FloatProperty* arrow_alpha_property_;
  rviz::FloatProperty* arrow_length_property_;

  rviz::BoolProperty* do_display_sphere_;
  rviz::ColorProperty* sphere_color_property_;
  rviz::FloatProperty* sphere_alpha_property_;
  rviz::FloatProperty* sphere_radius_property_;

  rviz::IntProperty* lower_bound_reachability_;
  rviz::IntProperty* upper_bound_reachability_;
  rviz::BoolProperty* is_byReachability_;
  rviz::EnumProperty* shape_property_;
  rviz::EnumProperty* disect_property_;
};

}  // end namespace reachability_map_visualizer
#endif  // REACHABILITY_MAP_DISPLAY_H
