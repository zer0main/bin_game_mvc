math = require('math')

local state
local size

function getDeskSize()
    size = math.random(2, 9)
    state = {}
    for i = 0, size - 1 do
        state[i] = {}
    end
    return size
end

function getWinNumber()
    return math.random(200, 1000)
end

function getIndex()
    return 1, 1, 1, 1
end

function output(model)
    local p = Point()
    for col = 0, size -1 do
        for row = 0, size - 1 do
           p.col = col;
           p.row = row;
           state[col][row] = model:getDeskNumber(p)
        end
    end
end

function think
