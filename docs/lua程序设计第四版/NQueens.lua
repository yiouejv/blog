function solve_nqueens(n)
    local ans, slove = {}, {}
    for i=1, n do
        local v = {}
        for j=1, n do table.insert(v, '-') end
        table.insert(slove, v)
    end
    
    local path = {}
    backtracking(ans, slove, path, 1, n)
    return ans;
end

function backtracking(ans, slove, path, level, n)
    if level == n + 1 then
        local t = copy(slove)
        table.insert(ans, t)
        return
    end

    for j=1, n do
        if isplaceok(pos, path, level, j) then
            slove[level][j] = 'Q'; table.insert(path, {level, j})
            backtracking(ans, slove, path, level+1, n)
            slove[level][j] = '-'; table.remove(path, #path)
        end
    end
end

function copy(tb)
    local t = {}
    for i, v in ipairs(tb) do
        if type(v) == "table" then
            t[i] = copy(v)
        else
            t[i] = v
        end
    end
    return t
end

function isplaceok(pos, path, level, j)
    for lvl, pos in ipairs(path) do
        local x, y = pos[1], pos[2]
        if y == j then return false end  -- 竖向
        
        -- 斜向
        local c = level - lvl  -- 目标行到当前遍历行差几行
        local left_j, right_j = y - c, y + c
        if left_j == j then return false end
        if right_j == j then return false end
    end
    return true
end