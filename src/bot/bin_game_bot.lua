math = require('math')

function getDeskSize()
    return math.random(3, 4)
end

function getWinNumber()
    return 100
end

function getIndex()
    return 1, 1, 1, 1
end

function output(model)
    print("getRowNumber " .. model:getRowNumber())
    local p = Point()
    p.col = 1
    p.row = 1
    print("getDeskNumber " .. model:getDeskNumber(p))
end

