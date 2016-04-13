local ffi = require("ffi")
local C = ffi.C
local log = ngx.log
local DEBUG = ngx.DEBUG

local _M = { _VERSION = '0.01'}

ffi.cdef[[
    int socket(int domain, int type, int protocel);
]]

local domain = 2
local type = 2
local protocel = 0

function getlocalip()
    local  sfd = C.socket(domain, type, protocel)
    if sfd < 0 then
        return nil
    end
    
    
end



log(DEBUG, "socket result is " .. sfd)





