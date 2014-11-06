--[[
Global variables:
* int size
* state[0-col][0-row] = value of cell

Functions called from C++:
* int getDeskSize()
* int getWinNumber()
* int getTimeNumber()
* 0-int, 0-int, 0-int, 0-int getIndex()
    returns coordinates of joined cells
* output(model)
    provides current state of game

model has the following methods:
* int getDeskNumber(point)
    returns value of cell

Point has the following fields:
* 0-int col
* 0-int row

Move has the following fields:
* Point p1
* Point p2
* bool undo_action

type move_table:
is array of instances of Move

Utility lua-functions (not called from C++ directly):
* move_table searchNearbyCells()
    returns move_table of all nearby move
* move_table equalCells(move_table, state)
    returns table of equal move (filters move_table)
    for specified state of desk
* int scoreOf(move)
    returns score of the move.
    This function counts possible steps on the next step
    after applying move and multiplies it with
    value of merged cells.
* move bestStep(move_table)
    returns the best move for new step from move_table.
    Uses scoreOf as scoring function.
* move_table cloneState(original_state)
    returns copy of a state
--]]

math = require('math')
os = require('os')
local state
local size

function getDeskSize()
    os.execute("sleep 2")
    size = math.random(2, 9)
    state = {}
    for i = 0, size - 1 do
        state[i] = {}
    end
    return size
end

function getWinNumber()
    os.execute("sleep 2")
    return math.random(200, 1000)
end

function getTimeNumber()
    os.execute("sleep 2")
    return math.random(1, 10)
end

function output(model)
    local p = Point()
    for col = 0, size - 1 do
        for row = 0, size - 1 do
            p.col = col
            p.row = row
            state[col][row] = model:getDeskNumber(p)
        end
    end
end

function getIndex()
    os.execute("sleep 2")
    local nearby_move = searchNearbyCells()
    local equal_move = equalCells(nearby_move, state)
    local p = bestStep(equal_move)
    return p.p1.col, p.p1.row, p.p2.col, p.p2.row
end

function searchNearbyCells()
    local move_table = {}
    for col = 0, size - 1 do
        for row = 0, size - 1 do
            local ps = Move()
            ps.p1.col = col
            ps.p1.row = row
            if col == 0 and row < size - 1 then
                ps.p2.col = col
                ps.p2.row = row + 1
                table.insert(move_table, ps)
            elseif col > 0 and row == size - 1 then
                ps.p2.col = col - 1
                ps.p2.row = row
                table.insert(move_table, ps)
            elseif col == 0 and row == size - 1 then
                break
            else
                ps.p2.col = col - 1
                ps.p2.row = row
                table.insert(move_table, ps)
                local ps = Move()
                ps.p1.col = col
                ps.p1.row = row
                ps.p2.col = col
                ps.p2.row = row + 1
                table.insert(move_table, ps)
            end
        end
    end
    return move_table
end

function equalCells(pt, st)
    local equal_cells = {}
    for _, p in ipairs(pt) do
        local p1c = p.p1.col
        local p1r = p.p1.row
        local p2c = p.p2.col
        local p2r = p.p2.row
        if st[p1c][p1r] == st[p2c][p2r] then
            table.insert(equal_cells, p)
        end
    end
    return equal_cells
end

function bestStep(pt)
    local best_move = pt[1]
    local max_score = scoreOf(best_move)
    for _, p in ipairs(pt) do
        if scoreOf(p) > max_score then
            max_score = scoreOf(p)
            best_move = p
        end
    end
    return best_move
end

function scoreOf(move)
    local merge_cells = state[move.p1.col][move.p1.row] * 2
    local steps_number = countSteps(move)
    local result = merge_cells * steps_number
    return result
end

function countSteps(pts)
    local future_state = cloneState(state)
    local i1c = pts.p1.col
    local i1r = pts.p1.row
    local i2c = pts.p2.col
    local i2r = pts.p2.row
    future_state[i2c][i2r] = future_state[i2c][i2r] * 2
    while i1c ~= size - 1 do
        future_state[i1c][i1r] = future_state[i1c + 1][i1r]
        i1c = i1c + 1
    end
    future_state[i1c][i1r] = 2
    pt = searchNearbyCells()
    eq_pt = equalCells(pt, future_state)
    return #eq_pt
end

function cloneState(state)
    local pt = {}
    for col = 0, size - 1 do
        pt[col] = {}
        for row = 0, size - 1 do
            pt[col][row] = state[col][row]
        end
    end
    return pt
end
