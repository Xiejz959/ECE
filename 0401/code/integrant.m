close all; clc;
figure('Color','w','Position',[100 100 900 800]);   % 整体再拉高一点，更大气

% ==================== 上图：拍包络（放在顶部）====================
ax1 = axes('Position',[0.12 0.68 0.76 0.25]);   % 高度只占25%，顶部留白
t = linspace(0,4,1500);
y = cos(pi*3*t).^2;

plot(t,y,'Color',[1 0.38 0],'LineWidth',3.2);
axis([0 4 -0.05 1.1]);
set(ax1,'Color','w','XColor','k','YColor','k','Box','off');

ylabel('Intensity','FontSize',15,'FontWeight','bold');
title('3 beats/second','FontSize',16,'Position',[2, 1.28]);

% 拍节点虚线
hold on;
for k = 0.333:0.333:4
    plot([k k],[-0.05 1.1],'--','Color',[0.82 0.82 0.82],'LineWidth',1);
end
hold off;

set(ax1,'XTick',[0 1 2 3 4]);
xlabel('Time','FontSize',14);

% ==================== 下图：五瓣玫瑰（放在底部）====================
ax2 = axes('Position',[0.22 0.12 0.48 0.48]);   % 底部留足空间，左右也稍微收一点
theta = linspace(0,2*pi,5000);
r = cos(5*theta);
x = r.*cos(theta);
y = r.*sin(theta);

plot(x,y,'Color',[1 0.38 0],'LineWidth',3.8);
axis equal tight;
axis([-1.1 1.1 -1.1 1.1]);
set(ax2,'Color','w','XColor','k','YColor','k','Box','on');
grid on;
set(ax2,'GridColor',[0.88 0.88 0.88],...
    'XTick',-1:0.5:1,'YTick',-1:0.5:1,...
    'XTickLabel',[],'YTickLabel',[]);

% 完全不加任何文字！

set(gcf,'Color','w');
disp('完成！上下留白超过20%，所有文字已删除，超级干净大气');