map = Map("watson-sender")

section = map:section(NamedSection, "watson_sender_sct", "watson-sender", "Watson configuration")

orgId = section:option(Value, "orgId", "Organization ID", "Organization ID")
orgId.datatype = "string"

typeId = section:option(Value, "typeId", "Device type", "Device type")
typeId.datatype = "string"

deviceId = section:option(Value, "deviceId", "Device ID", "Device ID")
deviceId.datatype = "string"

token = section:option(Value, "token", "Auth token", "Auth token")
token.datatype = "string"

flag = section:option(Flag, "enable", "Enable", "Enable service")

return map
