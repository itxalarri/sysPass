<div id="actionsBar-wrap">
    <div id="actionsBar">
        <ul>
            <?php
            foreach ($actions as $action): ?>
                <?php if ($action['checkaccess'] && !\SP\Acl::checkUserAccess($action['name'])): ?>
                    <?php continue; ?>
                <?php endif; ?>

                <?php if ($action['name'] == \SP\Controller\ActionsInterface::ACTION_EVL && !\SP\Util::logIsEnabled()): ?>
                    <?php continue; ?>
                <?php endif; ?>

                <li class="round" title="<?php echo _($action['title']); ?>"
                    OnClick="sysPassUtil.Common.doAction(<?php echo $action['name']; ?>)"><img
                        src="<?php echo \SP\Init::$WEBROOT, '/imgs/', $action['img']; ?>"/></li>
            <?php endforeach; ?>
        </ul>
    </div>
</div>
<div id="content"></div>
