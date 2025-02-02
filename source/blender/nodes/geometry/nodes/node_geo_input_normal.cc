/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#include "node_geometry_util.hh"

namespace blender::nodes::node_geo_input_normal_cc {

static void node_declare(NodeDeclarationBuilder &b)
{
  b.add_output<decl::Vector>("Normal").field_source();
}

static void node_geo_exec(GeoNodeExecParams params)
{
  Field<float3> normal_field{std::make_shared<bke::NormalFieldInput>()};
  params.set_output("Normal", std::move(normal_field));
}

static void node_register()
{
  static blender::bke::bNodeType ntype;

  geo_node_type_base(&ntype, "GeometryNodeInputNormal", GEO_NODE_INPUT_NORMAL);
  ntype.ui_name = "Normal";
  ntype.ui_description =
      "Retrieve a unit length vector indicating the direction pointing away from the geometry at "
      "each element";
  ntype.enum_name_legacy = "INPUT_NORMAL";
  ntype.nclass = NODE_CLASS_INPUT;
  ntype.geometry_node_execute = node_geo_exec;
  ntype.declare = node_declare;
  blender::bke::node_register_type(&ntype);
}
NOD_REGISTER_NODE(node_register)

}  // namespace blender::nodes::node_geo_input_normal_cc
