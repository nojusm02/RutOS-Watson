module("luci.controller.watson_sender_controller", package.seeall)

function index()
    entry({"admin", "services", "watson"}, cbi("watson_sender_model"), "Watson", 0)
end 
