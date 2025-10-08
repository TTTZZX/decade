void people_move()	//难度：3
{// 获取当前人物位置
	int current_x = people_pos[0];
	int current_y = people_pos[1];
// 根据方向键确定移动方向
	int dx = 0;
	int dy = 0;
	switch (dire) {
	case 72:dy = -1; break;//上
	case 80:dy = 1; break;//下
	case 75:dx = -1; break;//左
	case 77:dx = 1; break;//右
	default:return;//非方向键不处理
	}
// 计算新位置
	int new_x = current_x + dx;
	int new_y = current_y + dy;
// 边界检查
	if (new_x < 0 || new_x >= 31 || new_y < 0 || new_y >= 31) {
		return;
	}
// 检查目标位置类型
	int target_cell = world[new_x][new_y];
// 如果是空地，开始冲刺移动
	if (target_cell == 0) {
    // 保存原始位置用于清除
		int old_pos[2] = { current_x,current_y };
	// 持续移动直到遇到障碍物或边界
		while (1) {
			//更新新位置
			new_x += dx;
			new_y += dy;
			// 检查边界
			if (new_x < 0 || new_x >= 31 || new_y < 0 || new_y >= 31) {
				// 碰到边界，回退一步
				new_x -= dx;
				new_y -= dy;
				break;
			}

			// 检查新位置是否可移动
			if (world[new_x][new_y] != 0) {
				// 碰到障碍物，回退一步
				new_x -= dx;
				new_y -= dy;
				break;
			}
         }
	// 更新人物位置
		world[current_x][current_y] = 0;  // 清空原位置
		people_pos[0] = new_x;
		people_pos[1] = new_y;
		world[new_x][new_y] = 2;          // 设置新位置
	// 调用people_view更新显示
		people_view(old_pos);
	}
// 如果是门，直接移动
	else if (target_cell == 3) {
	// 保存旧位置
		int old_pos[2] = { current_x, current_y };
		world[current_x][current_y] = 0;
		people_pos[0] = new_x;
		people_pos[1] = new_y;
		world[new_x][new_y] = 2;
	// 调用people_view更新显示
		people_view(old_pos);
	}
// 如果是刺或墙，不移动
	else {
		return;
	}
	// 移动完成后检查游戏状态
	after_move_check();
}
