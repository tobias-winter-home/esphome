import esphome.codegen as cg
from esphome.components import canbus
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ["canbus"]

open3e_ns = cg.esphome_ns.namespace("open3e")
Open3EComponent = open3e_ns.class_("Open3EComponent", cg.PollingComponent)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(Open3EComponent),
        cv.Required("canbus_id"): cv.use_id(canbus.CanbusComponent),
    }
).extend(cv.polling_component_schema("60s"))


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)

    canbus_component = yield cg.get_variable(config["canbus_id"])
    cg.add(var.set_canbus(canbus_component))
