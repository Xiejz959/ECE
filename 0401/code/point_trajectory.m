clear; clc; close all;

t = 0;                        % 点在 (1,0)
z = exp(1j*t);                % = 1 + 0i
v = 1j*z;                     % = 0 + 1i   (向上)

figure('Color','w','Position',[600 400 750 700]);
hold on; axis equal;

% 1. 绿色虚线单位圆 + 轨迹小箭头
theta = linspace(0,2*pi,800);
plot(cos(theta),sin(theta),'--','Color',[0 0.55 0],'LineWidth',2.2);
plot(0.75*cos(5*pi/3), 0.75*sin(5*pi/3), '<', ...
     'MarkerFaceColor',[0 0.55 0],'MarkerEdgeColor',[0 0.55 0], ...
     'MarkerSize',9,'LineWidth',2);

% 2. 实轴、虚轴（深蓝色）
plot([-1.9 1.9],[0 0],'Color',[0.15 0.3 0.55],'LineWidth',2);
plot([0 0],[-1.4 1.9],'Color',[0.15 0.3 0.55],'LineWidth',2);

% 轴箭头
quiver(1.75,0,0.12,0,0,'Color',[0.15 0.3 0.55],'LineWidth',2.2,'MaxHeadSize',0.9);
quiver(0,1.75,0,0.12,0,'Color',[0.15 0.3 0.55],'LineWidth',2.2,'MaxHeadSize',0.9);

% 3. 位置向量（红色粗线）
plot([0 real(z)],[0 imag(z)],'-','Color',[0.85 0.1 0.1],'LineWidth',3.8);

% 4. 当前点 + 绿色小箭头指向它
plot(1,0,'o','MarkerFaceColor',[0.85 0.1 0.1],'MarkerEdgeColor','k','MarkerSize',11,'LineWidth',1.8);
quiver(1.15,-0.08,-0.12,0.08,0,'Color',[0 0.55 0],'LineWidth',2,'MaxHeadSize',1.2);

% 5. 速度向量（黑色向上）
quiver(1,0,real(v),imag(v),0,'k','LineWidth',3.8,'MaxHeadSize',0.7);

% 6. 所有文字（全部水平，位置和原图一致）
text(1.82, 0.05,      'Real axis',       'FontSize',13,'Color',[0.15 0.3 0.55],'HorizontalAlignment','center','FontName','Arial');
text(-0.25, 1.82,      'Imaginary axis',   'FontSize',13,'Color',[0.15 0.3 0.55],'HorizontalAlignment','center','FontName','Arial');

text(0.55, -0.09,      'Position $e^{it}$', 'FontSize',14,'Color',[0.85 0.1 0.1],'Interpreter','latex','FontName','Arial');
text(1.05, 0.55,       'Velocity $i e^{it}$','FontSize',14,'Color','k','Interpreter','latex','HorizontalAlignment','left','FontName','Arial');

text(1.28, -0.08,      'Moving point',     'FontSize',13,'Color',[0 0.55 0],'FontName','Arial');
text(0.65, -0.85,      'Moving trajectory','FontSize',13,'Color',[0 0.55 0],'FontName','Arial');


xlim([-2 2]); ylim([-1.45 2]);
axis off;
hold off;