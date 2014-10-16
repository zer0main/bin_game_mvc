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

function getTimeNumber()
    return math.random(1, 10)
end

function getIndex()
    local pts = Points()
    pts = think()
    return pts.p1.col, pts.p1.row, pts.p2.col, pts.p2.row
end

function output(model)
    local p = Point()
    for col = 1, size do
        for row = 1, size do
           p.col = col;
           p.row = row;
           state[col][row] = model:getDeskNumber(p)
        end
    end
end

function think()
    local pnts_mrk_lst = setPointsList()
    for p1 = 1, tableLength(pnts_mrk_lst) do
        local pnt1 = state[pnts_mrk_lst[p1].p1.col] + state[pnts_mrk_lst[p1].p1.row]
        local pnt2 = state[pnts_mrk_lst[p1].p2.col] + state[pnts_mrk_lst[p1].p2.row]
        local mark = pnt1 + pnt2
        local steps_number = countSteps(pnts_mrk_lst[p1])
        pnts_mrk_lst[p1][p1] = mark * steps_number
    end
    return bestStep(pnts_mrk_lst)
end

function setPointsList()
    local pts = Points()
    local points_list = {}
    for col1 = 1, size do
        pts.p1.col = col1
        for row1 = 1, size do
            pts.p1.row = row1
            for col2 = 1, size do
                pts.p2.col = col2
                for row2 = 1, size do
                    pts.p2.row = row2
                    if checkStep(pts) then
                        points_list[col1] = pts
                    end
                end
            end
        end
    end
    return points_list
end

function tableLength(table)
    local count = 0
    for _ in pairs(table) do count = count + 1 end
    return count
end

function checkStep(pts)
    local n1 = state[pts.p1.col][pts.p1.row]
    local n2 = state[pts.p2.col][pts.p2.rpw]
    return checkIndex(pts) and n1 == n2
end

function checkIndex(pts)
    local p1c = pts.p1.col
    local p1r = pts.p1.row
    local p2c = pts.p2.col
    local p2r = pts.p2.row
    if (p1c == p2c) and (math.abs(p1r - p2r) == 1) then
        return true
    elseif (p1r == p2r) and (math.abs(p1c - p2c) == 1) then
        return true
    end
    return false
end

function bestStep(pnts_mrk_lst)
    local saver
    local max = pnts_mrk_lst[1][1]
    for i = 2, tableLength(pnts_mrk_lst) do
        if pnts_mrk_lst[i][i] > max then
            max = pnts_mrk_lst[i]
            saver = i
        end
    end
    return pnts_mrk_lst[saver]
end

function countSteps(pts)
    future_state = replace(pts)
    local pnts_lst = setPointsList()
    return tableLength(pnts_lst)
end

function replace(pts)
    local future_state = state
    local i1c = pts.p1.col
    local i1r = pts.p1.row
    local i2c = pts.p2.col
    local i2r = pts.p2.row
    future_state[i1c][i1r] = future_state[i2c][i2r] * 2
    while i1c ~= size do
        future_state[i1c][i1r] = future_state[i1c + 1][i1r]
        i1c = i1c + 1
    end
    future_state[i1c][i1r] = 2
    return future_state
end
